#include "CNode.h"

CNode::CNode() {

	ParentNode = ChildNode = nullptr;
}
CNode::CNode(CNode* node) {
	ParentNode = ChildNode = nullptr;
	PrevNode = NextNode = this;
	AttachTo(node);
}

CNode::~CNode()
{
	Detach();
	while (ChildNode) {
		delete ChildNode;
	}
}

bool CNode::HasParent()
{
	return ParentNode!=nullptr;
}

bool CNode::HasChild()
{
	return ChildNode!=nullptr;
}

bool CNode::IsFirstChild()
{
	if (ParentNode) {
		return ParentNode->ChildNode == this;
	}
	else {
		return false;
	}
	
}

bool CNode::IsLastChild()
{
	if (ParentNode) {
		return ParentNode->ChildNode->PrevNode == this;
	}
	else {
		return false;

	}
}

void CNode::AttachTo(CNode* newParent)
{
	if (ParentNode) {
		Detach();
	}
	ParentNode = newParent;
	if (ParentNode->ChildNode) {
		PrevNode = ParentNode->ChildNode->PrevNode;
		NextNode = ParentNode->ChildNode;
		ParentNode->ChildNode->PrevNode->NextNode = this;
		ParentNode->ChildNode->PrevNode = this;
	}
	else {
		ParentNode->ChildNode = this;
	}

}

void CNode::Attach(CNode* newChild)
{
	if (newChild->HasParent()) {
		newChild->Detach();
	}
	newChild->ParentNode = this;
	if (ChildNode) {
		newChild->PrevNode = ChildNode->PrevNode;
		newChild->NextNode = ChildNode;
		ChildNode->PrevNode->NextNode = newChild;
		ChildNode->PrevNode = newChild;
	}
	else {
		ChildNode = newChild;
	}
}

void CNode::Detach()
{
	if (ParentNode && ParentNode->ChildNode == this) {
		if (NextNode != this) {
			ParentNode->ChildNode = NextNode;
		}
		else {
			ParentNode->ChildNode = nullptr;
		}
		PrevNode->NextNode = NextNode;
		NextNode->PrevNode = PrevNode;
		PrevNode = this;
		NextNode = this;
	}
}

int CNode::CountNodes()
{
	if (ChildNode) {
		return ChildNode->CountNodes() + 1;
	}
	else {
		return 1;
	}
}
