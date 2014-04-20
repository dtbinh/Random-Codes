#include "GameObject.h"

GameObject::GameObject()
{
	transform.position.x = transform.position.y = 0;
	transform.scale.x = transform.scale.y = 1;
	angle = 0;
}

GameObject::~GameObject()
{

}

void GameObject::setCollider(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	collider.v1.x = x1;
	collider.v1.y = y1;
	collider.v2.x = x2;
	collider.v2.y = y2;
	collider.v3.x = x3;
	collider.v3.y = y3;
	collider.v4.x = x4;
	collider.v4.y = y4;
}

float GameObject::getMaxX()
{
	return collider.v3.x;
}

float GameObject::getMaxY()
{
	return collider.v3.y;
}

float GameObject::getMinX()
{
	return collider.v1.x;
}

float GameObject::getMinY()
{
	return collider.v1.y;
}

void GameObject::setTx(float x)
{
	transform.position.x = x;
}

void GameObject::setTy(float y)
{
	transform.position.y = y;
}

float GameObject::getTx(void)
{
	return transform.position.x;
}

float GameObject::getTy(void)
{
	return transform.position.y;
}

float GameObject::getEx(void)
{
	return transform.scale.x;
}

float GameObject::getEy(void)
{
	return transform.scale.y;
}

float GameObject::getAngle(void)
{
	return angle;
}

void GameObject::incrementAngle()
{
	angle += 1;
}

void GameObject::decrementAngle()
{
	angle -= 1;
}

void GameObject::incrementTx()
{
	transform.position.x += 10;
	collider.v1.x += 10;
	collider.v2.x += 10;
	collider.v3.x += 10;
	collider.v4.x += 10;
}

void GameObject::incrementTy()
{
	transform.position.y += 10;
	collider.v1.y += 10;
	collider.v2.y += 10;
	collider.v3.y += 10;
	collider.v4.y += 10;
}

void GameObject::incrementEx()
{
	transform.scale.x += 0.1;
}

void GameObject::incrementEy()
{
	transform.scale.y += 0.1;
}

void GameObject::decrementTx()
{
	transform.position.x -= 10;
	collider.v1.x -= 10;
	collider.v2.x -= 10;
	collider.v3.x -= 10;
	collider.v4.x -= 10;
}

void GameObject::decrementTy()
{
	transform.position.y -= 10;
	collider.v1.y -= 10;
	collider.v2.y -= 10;
	collider.v3.y -= 10;
	collider.v4.y -= 10;
}

void GameObject::decrementEx()
{
	transform.scale.x -= 0.1;
}

void GameObject::decrementEy()
{
	transform.scale.y -= 0.1;
}
