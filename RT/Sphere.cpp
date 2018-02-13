#include "Sphere.h"
#include "Common.h"

float CRTSphere::GetNearestIntersectionsDistance (const CRTRay &rRay)
{
	CRTPoint vCO = rRay.GetOrigin () - m_vCenter ;

	float fB = (vCO.Dot(rRay.GetDirection())) ;
	float fC = (vCO.Dot(vCO))-m_fRadius*m_fRadius ;

	float fDisc = fB * fB - fC ;

	if (fDisc<0)
		return RT_INFINITE ;
	
	CRTVector vNormal ;
	float fDistance ;
	float fSqrtDisc = sqrt (fDisc) ;

	fDistance = - fB - fSqrtDisc ;
	return fDistance ;
}

