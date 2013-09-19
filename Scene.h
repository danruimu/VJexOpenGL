#pragma once

#define	CUBE	10

class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);
	void render(void);
	void buildCube(void);

private:
	float alfa;
};

