#ifndef __OBJECT_H
#define __OBJECT_H

#include "Ray.h"
#include "Color.h"

class CRTObject
{
	public :

		CRTObject ()  :	m_cColor(CRTColor(1.0f,1.0f,1.0f))
		{
		}

		virtual ~CRTObject ()
		{

		}

		void SetColor (const CRTColor &cColor) { m_cColor = cColor ; }
		const CRTColor &GetColor () { return m_cColor ; }

		virtual CRTVector getNormale (CRTPoint &pPoint) =  0;

		virtual float GetNearestIntersectionsDistance (const CRTRay &rRay) = 0 ;

	protected :

		CRTColor m_cColor ;
} ;

#endif

