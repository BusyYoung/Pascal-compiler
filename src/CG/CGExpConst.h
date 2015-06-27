#ifndef _CGEXPCONST_H_
#define _CGEXPCONST_H_

#include "CGGlobal.h"
using namespace std;

class CGExpConst : public CGFunction {

public:
	CGExpConst(CodeGenerator *cg) : CGFunction(cg) {}
	virtual ~CGExpConst() {}
	
	virtual void operator()(TreeNode *pnode);
};

void CGExpConst::operator()(TreeNode *pnode) {
	
	if (pnode->type != EXPTYPE_REAL) {
		int value;
		if (pnode->type == EXPTYPE_CHAR) {
			value = pnode->attr.char_val;
		}
		else {
			value = pnode->attr.val;
		}
		stringstream ss;
		ss << "mov eax, " << value;
		writelnCode(ss.str());
	}
	else {
		double value = pnode->attr.real_val;
		string realDataLabel = LabelManager::getDataLabel(value, codeGenerator);
		writelnCode("mov eax, dword ptr " + realDataLabel);
	}
}

#endif