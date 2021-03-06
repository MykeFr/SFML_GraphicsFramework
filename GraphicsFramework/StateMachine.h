#pragma once

#include "GraphicsFramework/holders.h"

#include <map>
#include <functional>

namespace GF
{
	class StateMachine
	{
	public:

		StateMachine();

		bool onCreate();
		bool onHandleEvent(GF::Event& event);
		bool onUpdate(float fElapsedTime, float fTotalTime);
		bool onDraw();
		void onDestroy();

		bool change(const std::string& stateName, State* state = nullptr);
		void add(const std::string& name, State* state);
		void deleteState(const std::string& stateName);

		void checkSwitchState();
		
	private:
		std::map<std::string, State*> activeStates;
		std::map<std::string, State*> mStates;
		State* mCurrentState;
		std::string mCurrentStateName;
		std::string lastState;
		bool readyToSwitch;
	};
}