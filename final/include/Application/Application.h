//
// Created by lenovo on 2024/11/7.
//

#ifndef FINAL_APPLICATION_H
#define FINAL_APPLICATION_H

#include <string>
#include <map>
#include <queue>
#include <tuple>
class Scene;
using std::string;
using std::map;
using std::queue;
using std::tuple;
using std::get;
class InputReceiver;
class InputErrorHandler;
class OutputDisplayer;
class DataManager;

enum class AppWatingList {
    DELETESCENE, CREATESCENE, SWITCHSCENE,
};

class Application {
public:
    Application(InputReceiver* _mpInputReceiver, InputErrorHandler* _mpInputErrorHandler,
                OutputDisplayer* _mpOutputDisplayer, DataManager* _mpDataManager);
    void setScenes(const map<string, Scene*>& _mScenes);
    void setRunningSceneName(const string& _mRunningSceneName);
    Application(InputReceiver* _mpInputReceiver, InputErrorHandler* _mpInputErrorHandler,
            OutputDisplayer* _mpOutputDisplayer, DataManager* _mpDataManager,
            const map<string, Scene*>& _mScenes, const string& _mRunningSceneName);
    Application(const Application& rhs) = delete;
    Application& operator=(const Application& rhs) = delete;
    virtual ~Application();
    const map<string, Scene*>& getScenes() const;
    const string& getRunningSceneName() const;
    InputReceiver* getInputReceiver();
    InputErrorHandler* getInputErrorHandler();
    OutputDisplayer* getOutputDisplayer();
    DataManager* getDataManager();
    void addWatingList(const tuple<AppWatingList, string, Scene*>& tp);
    void run();
    void temp_run2();
protected:
    void deleteScene(const string& sceneName);
    void createScene(const string& sceneName, Scene* scene);
    void switchScene(const string& sceneName);
    void solveWatingList();
    InputReceiver* mpInputReceiver;
    InputErrorHandler* mpInputErrorHandler;
    OutputDisplayer* mpOutputDisplayer;
    DataManager* mpDataManager;
    map<string, Scene*> mScenes;
    string mRunningSceneName;
    queue<tuple<AppWatingList, string, Scene*>> mWatingList;
};

#endif //FINAL_APPLICATION_H
