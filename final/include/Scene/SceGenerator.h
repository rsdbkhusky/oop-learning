//
// Created by lenovo on 2024/12/18.
//

#ifndef FINAL_SCEGENERATOR_H
#define FINAL_SCEGENERATOR_H

class Scene;
class Application;
class SceGenerParaList;

class SceGenerator {
public:
    virtual Scene* genScene(Application* application, SceGenerParaList* sceGenerParaList = nullptr);
};


#endif //FINAL_SCEGENERATOR_H
