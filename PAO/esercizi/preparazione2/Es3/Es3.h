//
// Created by Alberto Sinigaglia on 19/01/2020.
//

#ifndef LIBRERIELEZIONI_ES3_H
#define LIBRERIELEZIONI_ES3_H

#include <vector>
class Component;




class Container {
public:
    virtual ~Container();
    std::vector<Component*> getComponents() const;
};

class Component: public Container {};

class Button: public Component {
public:
    std::vector<Container*> getContainers() const;
};

class MenuItem: public Button {
public:
    void setEnabled(bool b = true);
};

class NoButton {};

Button** Fun(const Container& c){
    std::vector<Button*> v;
    for(auto* el : c.getComponents()){
        auto* b = dynamic_cast<Button*>(el);
        if(b){
            v.push_back(b);
            auto* m = dynamic_cast<MenuItem*>(el);
            if(m && m->getContainers().size()>1){
                m->setEnabled(false);
            }
        }
    }
    if(v.empty()) return nullptr;
    return &v[0];
}


#endif //LIBRERIELEZIONI_ES3_H
