//
// Created by seth on 6/8/20.
//

#include "core/types/Actor.h"

Actor::Actor()
{
  pos = glm::vec3(0.0f, 0.0f, 0.0f);
}

Actor::~Actor()
{
  for (Actor* actor : children)
  {
    delete actor;
  }

  for (ActorComponent* component : components) {
    delete component;
  }

  GameObjectManager::getInstance()->deregisterObject(this);
}

void Actor::addChild(Actor *child)
{
  children.push_back(child);
  child->parent = this;
}

void Actor::addComponent(ActorComponent *component)
{
  components.push_back(component);
  component->parent = this;
}

void Actor::tickComponents(float delta)
{
  for(ActorComponent* component : components)
  {
    component->tick(delta);
  }
}

void Actor::tickChildren(float delta)
{
  for(Actor* actor : children)
  {
    actor->tick(delta);
  }
}

void Actor::tick(float delta)
{
  this->process(delta);
  this->tickComponents(delta);
  this->tickChildren(delta);
}

void Actor::process(float delta) {}

glm::vec3 Actor::getWorldPosition() {
  if (parent != nullptr)
  {
    return parent->getWorldPosition() + pos;
  }
  else
  {
    return pos;
  }
}
