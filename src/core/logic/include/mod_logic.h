//
// Created by Viktor on 15.1.2021 г..
//

#ifndef MOD_LOGIC_H
#define MOD_LOGIC_H


class ModLogic {
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void post() = 0;
	virtual void reinit() = 0;
};


#endif //MOD_LOGIC_H
