//
//  SceneManager.h
//  Doodler
//
//  Created by Daniel Haaser on 6/2/15.
//
//

#ifndef __Doodler__SceneManager__
#define __Doodler__SceneManager__


class DrawingCanvas;

class SceneManager
{
public:
    static SceneManager* getInstance();

    void enterSoloGame();

    void returnToLobby();
    

private:
    DrawingCanvas* drawingCanvas;
    
    SceneManager();
    ~SceneManager();
    
    void loadDrawingScene(bool networked);
};

#endif /* defined(__Doodler__SceneManager__) */
