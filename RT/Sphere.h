#ifndef __SPHERE_H
#define __SPHERE_H

#include "Object.h"

class CRTSphere : public CRTObject
{
	public :

		CRTSphere (const CRTPoint &vCenter=CRTPoint(0.0f,0.0f,0.0f),float fRadius=1.0f)
			:	CRTObject	(),
				m_vCenter	(vCenter),
				m_fRadius	(fRadius)
		{
		}

		float GetNearestIntersectionsDistance (const CRTRay &rRay) ;

		CRTVector getNormale (CRTPoint &pPoint) {
		    return (pPoint - m_vCenter).Unit();

		}

	protected :

		CRTPoint m_vCenter ;
		float m_fRadius ;
} ;

#endif

