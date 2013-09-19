#pragma once

#define	CUBE	10
#define SVAS	11

class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);
	void render(void);
	void buildCube(void);
	void buildSvastic(void);

private:
	float alfa;
};