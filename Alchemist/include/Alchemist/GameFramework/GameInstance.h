#pragma once

#include <Alchemist/Alchemist.h>

class DLL GameInstance
{
	friend class Application;

public:
	GameInstance() = default;
	virtual ~GameInstance() = default;

public:
	GameInstance(const GameInstance&) = delete;
	GameInstance(GameInstance&&) = delete;

public:
	GameInstance& operator=(const GameInstance&) = delete;
	GameInstance& operator=(GameInstance&&) = delete;

protected:
	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;
	virtual void Render() = 0;
	virtual void EndPlay() = 0;

};