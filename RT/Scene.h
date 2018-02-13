#ifndef __SCENE_H
#define __SCENE_H

#include <vector>

#include "Color.h"
#include "Vector3d.h"
#include "Ray.h"
#include "Object.h"
#include "Light.h"

class CRTScene
{
	public :

		CRTScene () ;
		~CRTScene () ;

		void AddObject (CRTObject *pObject) { m_vObjects.push_back (pObject) ; }
		void AddLight (CRTLight *pLight) { m_vLights.push_back (pLight) ; }

		void Render(const char *pszFileName,unsigned int nWidth, unsigned int nHeight);

	protected :

		CRTColor Raytrace(const CRTRay &rRay, unsigned int nDepth);
		CRTObject *FindNearestObject(const CRTRay &rRay, float &fDistanceMin);

		std::vector<CRTObject*> m_vObjects ;
		std::vector<CRTLight*> m_vLights ;
} ;

#endif

