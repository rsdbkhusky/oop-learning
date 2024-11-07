//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_APPLICATION_H
#define FINAL_APPLICATION_H

class Scene;
class Application {
public:
    Application(Scene* _mStartScene);
    ~Application();
private:
    Scene* mStartScene;
};

#endif //FINAL_APPLICATION_H
