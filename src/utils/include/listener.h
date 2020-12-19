#ifndef LISTENER
#define LISTENER
/* Main class should extend this */
class Listener {
public:
    Listener() = default;
    virtual ~Listener() = default;
	virtual void create() = 0;
	virtual void render() = 0;
};

#endif