#pragma once
#include "Ynion.h"

class Goal : public Ynion::ScriptableEntity
{
public:
	virtual void OnCreate() override
	{
		m_ID = GetComponent<Ynion::IDComponent>().ID;
	}

	static uint64_t getID() { return m_ID; }
private:
	static uint64_t m_ID;
};
