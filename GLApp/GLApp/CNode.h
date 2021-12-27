#pragma once

class CNode {

	CNode* ParentNode;
	CNode* ChildNode;
	CNode* PrevNode;
	CNode* NextNode;

	CNode();
	CNode(CNode* node);
	~CNode();

	bool HasParent();
	bool HasChild();
	bool IsFirstChild();
	bool IsLastChild();
	void AttachTo(CNode* newParent);
	void Attach(CNode* newChild);
	void Detach();
	int CountNodes();
};
