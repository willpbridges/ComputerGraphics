#pragma once
#include <vector>
#include "Renderable.h"

class SceneNode {
protected:
	SceneNode * parent;
private:
	std::vector<SceneNode*> children;
	Renderable* object;
	QMatrix4x4 localTransform;
	QMatrix4x4 worldTransform;
	QVector4D color;
	QVector3D modelScale;
public:
	SceneNode(Renderable* obj = nullptr, QVector4D color = QVector4D(1,1,1,1));
	~SceneNode(void);

	void SetTransform(const QMatrix4x4 &matrix) {
		localTransform = matrix;
	}

	const QMatrix4x4 GetTransform() const {
		return localTransform;
	}

	QMatrix4x4 GetWorldTransform() const {
		return worldTransform;
	}

	QVector4D GetColor() const {
		return color;
	}

	void SetColor(QVector4D c) {
		color = c;
	}

	QVector3D GetModelScale() const {
		return modelScale;
	}

	void SetModelScale(QVector3D s) {
		modelScale = s;
	}

	Renderable* GetRenderable() const {
		return object;
	}

	void SetRenderable(Renderable * r) {
		object = r;
	}

	void AddChild(SceneNode * s);
	virtual void Update(float msec);
	virtual void Draw();
};