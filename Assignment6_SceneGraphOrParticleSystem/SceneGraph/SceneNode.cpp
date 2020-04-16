#include "SceneNode.h"

SceneNode::SceneNode(Renderable* obj, QVector4D colorVec) {
	object = obj;
	color = colorVec;
	parent = nullptr;
	modelScale = QVector3D(1, 1, 1);
}

SceneNode::~SceneNode(void) {
	for (unsigned int i = 0; i < children.size(); ++i) {
		delete children[i];
	}
}

void SceneNode::AddChild(SceneNode *s) {
	children.push_back(s);
	s->parent = this;
}

void SceneNode::Update(float msec) {
	if (parent) {
		worldTransform = parent->worldTransform * localTransform;
	}
	else {
		worldTransform = localTransform;
	}
	for (std::vector<SceneNode*>::iterator i = children.begin(); i != children.end(); ++i) {
		(*i)->Update(msec);
	}
}
