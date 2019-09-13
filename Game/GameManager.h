//
// Created by vhundef on 01.07.19.
//

#ifndef COURSEWORK_GAMEMANAGER_H
#define COURSEWORK_GAMEMANAGER_H


#include <fstream>
#include "SDL/SDL.h"
#include "MapManager.h"
#include "BotController.h"

class GameManager {
private:
    MapManager *mapManager;
    ScreenManager *screenManager;
    int elapsed = 0, current = 0, timeSinceSecond = 0, frames = 0, next{}; //avgFPS - Avg fps per second
    int framerate = 59;
    list<BotController> bots;
    list<Tank> tanks;
    SDL_Event event{}; ///< Holds last event


    void prestartInit() {
        // ===== Setting initial values
        setFramerate(110);
        mapManager->setCurrentMap(GameObject::randIntInRange(2, 7));
        mapManager->getCurrentMap()->reDraw();
        tanks.clear();
        bots.clear();
        tanks.emplace_back(screenManager, mapManager);
        bots.emplace_back(&tanks.back(), screenManager);
        tanks.back().spawnAtRandomLocation();
        tanks.emplace_back(screenManager, mapManager);
        bots.emplace_back(&tanks.back(), screenManager);
        tanks.back().spawnAtRandomLocation();

    }

    static void writeScoreToFile(const string &playerName, int Score) {
        std::ofstream outfile;

        outfile.open("leaderBoard", std::ios_base::app);
        outfile << playerName << " " << Score << "\n";
        outfile.close();
    }


public:
    GameManager(ScreenManager *screenMgr, MapManager *mapMgr) {
        screenManager = screenMgr;
        mapManager = mapMgr;
    }

    void setFramerate(int purposedFPS) {
        GameManager::framerate = purposedFPS;
    }

    bool swtch = true;

    void capFPS() {
        if (swtch) {
            elapsed = (int) SDL_GetTicks() - current;
            current += elapsed;
            timeSinceSecond += elapsed;
            frames++;
            if (timeSinceSecond >= 1000) {
                timeSinceSecond = 0;
                frames = 0;
            }
        } else {
            next = SDL_GetTicks();
            if (next - current < 1000.0 / framerate) {
                SDL_Delay(1000.f / (float) framerate - (float) (next - current));
            }
        }
        swtch = !swtch;
    }

    static bool checkForCollision(Particle *particle, Tank *tank) {
        return particle->location.x1 >= tank->location.x1 &&
               particle->location.x2 <= tank->location.x2 &&
               particle->location.y1 >= tank->location.y1 &&
               particle->location.y2 <= tank->location.y2;
    }

    int startGame(EventManager eventManager, UI_Manager uiManager, Tank player) {
        prestartInit();
        player.spawnAtRandomLocation();
        while (true) {
            capFPS();

            tanks.remove_if(Tank::removalCheck);
            bots.remove_if(BotController::removalCheck);
            if (bots.empty()) {
                tanks.emplace_back(screenManager, mapManager);
                bots.emplace_back(&tanks.back(), screenManager);
                tanks.back().spawnAtRandomLocation();
                tanks.emplace_back(screenManager, mapManager);
                bots.emplace_back(&tanks.back(), screenManager);
                tanks.back().spawnAtRandomLocation();
            }
            event = eventManager.getEvent();
            {

                if (event.type == SDL_QUIT) {
                    /*  int tmp=uiManager.showPauseMenu(screenManager,&eventManager);
                      if(tmp==3){
                          break;
                      }
                      if(tmp==2){
                          uiManager.showRules();
                      }*/
                    break;

                }
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
                    player.setMovementDirection(-1);
                    player.setMovementSpeed(1);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
                    player.setMovementDirection(1);
                    player.setMovementSpeed(1);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP) {
                    player.setMovementDirection(2);
                    player.setMovementSpeed(1);
                } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
                    player.setMovementDirection(-2);
                    player.setMovementSpeed(1);
                }

                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
                    player.shoot();
                if (event.type == SDL_KEYUP)
                    player.setMovementSpeed(0);

            }
            screenManager->clearScreen();
            mapManager->getCurrentMap()->reDraw();
            /* ==== Redrawing game objects ====*/
            for (auto &bot : bots) {
                bot.moveTank();
                bot.controlledTank->reDraw();
                bot.shootPlayer(player.location);
            }

            //uiManager.drawBg();
            uiManager.drawHUD(player.getHealth(), player.getScore());
            player.reDraw();

            /* ==== Check for collisions ====*/
            for (auto &particle : player.weapon.particles) {
                for (auto &tank : tanks) {
                    if (checkForCollision(&particle, &tank)) {
                        particle.setIsOnScreem(false);
                        player.setScore(15);
                        tank.setHealth(-25); // THIS IS TEMPORARY
                    }
                }
                if (mapManager->getCurrentMap()->checkForCollision(particle.location)) {
                    particle.setIsOnScreem(false);
                }
            }

            for (auto &tank : tanks) {
                for (auto &particle : tank.weapon.particles) {
                    if (checkForCollision(&particle, &player)) {
                        particle.setIsOnScreem(false);
                        player.setHealth(-25); // THIS IS TEMPORARY
                    }
                    //cout << "==========================================================" << endl;
                    // cout << "Particle current position x1: " << particle.location.x1 << " x2: " << particle.location.x2
                    //    << " y1: " << particle.location.y1 << " y2: " << particle.location.y2 << endl;
                    if (mapManager->getCurrentMap()->checkForCollision(particle.location)) {
                        particle.setIsOnScreem(false);
                        cout << "Removed particle" << endl;
                    }
                    //  cout << "==========================================================" << endl;

                }
            }
            screenManager->updateScreen();

            capFPS();


            if (player.getHealth() <= 0) {
                writeScoreToFile(uiManager.input(),
                                 player.getScore()); ///< Asks user to input PlayerName than writes it and player score to the leaderBoard file
                return uiManager.showMainMenu(&eventManager, screenManager,&uiManager,mapManager, player.getScore());
            }
        }
        return -0xf;
    }
};


#endif //COURSEWORK_GAMEMANAGER_H
