#include <vector>

class Component;

class Container
{
public:
	virtual ~Container();
	std::vector<Component*> getComponents() const;
};

class Component: public Container {};

class Button: public Component
{
public:
	std::vector<Container*> getContainers() const;
};

class MenuItem: public Button {
public:
	void setEnabled(bool b = true);
};

class NoButton {};

Button** Fun(const Container& c)
{
	std::vector<Component *> components = c.getComponents();

	std::vector<Button *> vButtons;

	Buttons **buttons = nullptr;

	for(auto it = components.begin(); it != components.end(); ++it)
	{
		if(typeid(*(*it)) == typeid(Button))
		{
			Button *btn = static_cast<Button *>(*it);

			std::vector<Container *> containers = btn->getContainers();

			vButtons.push_back(btn);
		}
		else if(typeid(*(*it)) == typeid(MenuItem))
		{
			MenuItem *menuItem = static_cast<MenuItem *>(*it);

			if(menuItem->getContainers().size() >= 2) menuItem->setEnabled(false);


		}
	}

	if(!vButtons.empty())
	{
		buttons = new Buttons*[vButtons.size()];

		for(int i = 0; i < vButtons.size(); ++i)
		{
			buttons[i] = vButtons[i];
		}
	}

	return buttons;
}
