#ifndef __NSCOMPONENT_H__
#define __NSCOMPONENT_H__

class NSScene;
class NSObject;

class NSComponent
{
public:
	NSComponent(NSObject * o, int l, int t) : item(o), left(l), top(t) {}
	~NSComponent();
	void MoveUp(int s);
	void AddScript(const char * s);
	void SetScene(NSScene * s) { scene = s; }
	void Render(char * b, int bw, int bh);

private:
	NSObject * item;
	int left, top;	
	NSScene * scene;
};

#endif
