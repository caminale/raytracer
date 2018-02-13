#ifndef __RAY_H
#define __RAY_H

#include <vector>

#include "Point3d.h"

class CRTRay
{
	public :
	
		CRTRay ()
			:	m_vOrigin		(),
				m_vDirection	()
		{
		}

		CRTRay(const CRTPoint &vOrigin, const CRTVector &vDirection)
			:	m_vOrigin(vOrigin),
				m_vDirection(vDirection)
		{
		}
		
		void SetOrigin (const CRTVector &vOrigin) { m_vOrigin = vOrigin ; }
		void SetDirection (const CRTVector &vDirection) { m_vDirection = vDirection ; }

		const CRTVector &GetOrigin() const { return m_vOrigin ; }
		const CRTVector &GetDirection() const { return m_vDirection ; }
	
	protected :
	
		CRTPoint	m_vOrigin ;
		CRTVector	m_vDirection ;
} ;

#endif

