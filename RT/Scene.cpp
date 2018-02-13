#include "Scene.h"
#include "Common.h"
#include "Bmpfile.h"
#include <iostream>

using namespace std;

CRTScene::CRTScene ()
        :	m_vObjects		()
{
}

CRTScene::~CRTScene ()
{
    unsigned int i ;

    for (i = 0 ; i < m_vObjects.size() ; i++)
        delete m_vObjects[i] ;
    for (i = 0 ; i < m_vLights.size() ; i++)
        delete m_vLights[i] ;
}

void CRTScene::Render (const char *pszFileName, unsigned int nWidth,unsigned int nHeight)
{
    CRTRay rRay ;
    unsigned char *pColors = new unsigned char [nWidth*nHeight*3] ;
    float aspectRatio = float(nWidth)/float(nHeight);

    for (unsigned int nY=0;nY<nHeight;nY++)
    {
        for (unsigned int nX=0;nX<nWidth;nX++)
        {
            rRay.SetOrigin(CRTPoint(float(nX)/float(nWidth),float(nY)/(float(nHeight)*aspectRatio),0));
            rRay.SetDirection(CRTVector(0,0,1));

            CRTColor cColor = Raytrace(rRay, 0);
//            cout<<cColor.m_fB;
            pColors[3*(nY*nWidth+nX)+0] = int(255*MIN(cColor.m_fB,1.0f)) ;
            pColors[3*(nY*nWidth+nX)+1] = int(255*MIN(cColor.m_fG,1.0f)) ;
            pColors[3*(nY*nWidth+nX)+2] = int(255*MIN(cColor.m_fR,1.0f)) ;

        }
    }
    cout<<pszFileName;
    BMPFile::SaveBmp(pszFileName, pColors, nWidth, nHeight);
    delete []pColors ;
}

CRTColor CRTScene::Raytrace (const CRTRay &rRay,unsigned int nDepth)
{
    float distanceMin;

    CRTObject *myObject = FindNearestObject(rRay,distanceMin);
    CRTPoint pi = rRay.GetOrigin() + rRay.GetDirection() * distanceMin;
    CRTVector vN = myObject->getNormale(pi);
    float dt;
    CRTColor myFinalColor;

    for (unsigned int i=0;i<m_vLights.size();i++){

        CRTVector vL = m_vLights[i]->getDirectionTolightAtPoint(pi);
        vL =  m_vLights[i]->getDirectionTolightAtPoint(pi);
        myFinalColor+= m_vLights[i]->GetColor() * vL.Dot(vN);
    }


    // return myObject ? myObject->GetColor() : CRTColor() ;

    return myFinalColor * myObject->GetColor() ;

}

CRTObject *CRTScene::FindNearestObject(const CRTRay &rRay, float &fDistanceMin)
{
    fDistanceMin = RT_INFINITE;
    float tampDistance;
    CRTObject *pNearestObject = NULL ;
    for(int i = 0; i<m_vObjects.size(); i++){
        tampDistance = m_vObjects[i]->GetNearestIntersectionsDistance(rRay);
        if(tampDistance < fDistanceMin){
            fDistanceMin = tampDistance;
            pNearestObject = m_vObjects[i];
        }
    }
    return pNearestObject;
}

