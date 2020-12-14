#pragma once

/* Main class should extend this */
class Listener {
public:
	virtual void create() = 0;
	virtual void render() = 0;
	virtual void dispose() = 0;
};