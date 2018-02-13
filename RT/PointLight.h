#ifndef __POINTLIGHT_H
#define __POINTLIGHT_H
#include "Light.h"
#include "Point3d.h"

class CRTPointLight : public CRTLight
{
public :
	void SetOrigin (const CRTPoint &pOrigin) {
		origin = pOrigin ;
	}
	CRTPoint GetOrigin () { return origin; }
	CRTVector getDirectionTolightAtPoint (const CRTPoint &pPoint) {

		CRTVector returnValue = (origin - pPoint);
		return returnValue.Unit();
	}
protected :
	CRTPoint origin;




} ;

#endif
