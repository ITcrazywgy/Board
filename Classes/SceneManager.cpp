//
//  SceneManager.cpp
//  Doodler
//
//  Created by Daniel Haaser on 6/2/15.
//
//

#include "SceneManager.h"
#include "DrawingCanvas.h"
#include "cocos2d.h"

using namespace cocos2d;


static SceneManager* sharedSceneManager = nullptr;

SceneManager* SceneManager::getInstance()
{
    if (! sharedSceneManager)
    {
        sharedSceneManager = new SceneManager();
    }
    
    return sharedSceneManager;
}

SceneManager::SceneManager()
{
    drawingCanvas = nullptr;
}

SceneManager::~SceneManager()
{

}


void SceneManager::enterSoloGame()
{
    this->loadDrawingScene(false);
}



void SceneManager::returnToLobby()
{
    if (drawingCanvas)
    {
        Director::getInstance()->popScene();
        drawingCanvas = nullptr;
    }
}


#pragma mark -
#pragma mark Private Methods

void SceneManager::loadDrawingScene(bool networked)
{
    auto scene = Scene::create();
    
    drawingCanvas = DrawingCanvas::create();

    scene->addChild(drawingCanvas);
    
    Director::getInstance()->pushScene(scene);
}
