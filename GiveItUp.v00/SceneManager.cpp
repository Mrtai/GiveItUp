#include "stdafx.h"
#include "SceneManager.h"

SceneManager* SceneManager::m_pInstance = NULL;
State st = GameManagerState::getInstance()->getState();
SceneManager* SceneManager::GetInstance() {
	if (m_pInstance == NULL)
		m_pInstance = new SceneManager();
	return m_pInstance;
}
SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
	if (m_pInstance != NULL)
		delete SceneManager::GetInstance()->m_pInstance;
	SceneManager::GetInstance()->m_pInstance = 0;
}
Scene* SceneManager::GetCurrentScene() {
	return m_sCurrentScene;
}
void SceneManager::Init() {
	//shape.setFillColor(sf::Color::Red);
	m_sCurrentScene = new MenuScene();
	m_sCurrentScene->Init();
}
void SceneManager::Render(sf::RenderWindow &window) {
	m_sCurrentScene->Render(window);
}
void SceneManager::Update(float deltime,E &e) {
	m_sCurrentScene->Update(deltime,e);
}

