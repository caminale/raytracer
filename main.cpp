#include "RT/Scene.h"
#include "RT/Sphere.h"
#include "RT/PointLight.h"

int main()
{
	CRTScene scene;
	CRTSphere *pSphere ;
	CRTLight *pLight;
	CRTPointLight *source1 = new CRTPointLight();
	source1->SetOrigin(CRTPoint(-4,-4,-4));

	float fRadius = 0.17f;

	pSphere = new CRTSphere(CRTVector(0.35f,0.25f,1.0f), fRadius);
	pSphere->SetColor(CRTColor(1.0f, 0.0f, 0.0f));
	scene.AddObject(pSphere);
	pLight = new CRTPointLight();
	source1->SetColor(CRTColor(0.7f, 0.7f, 1.0f));
	scene.AddLight(source1);

	pSphere = new CRTSphere(CRTVector(0.65f,0.25f,1.0f), fRadius);
	pSphere->SetColor(CRTColor(0.0f, 1.0f, 0.0f));
	scene.AddObject(pSphere);

	pSphere = new CRTSphere(CRTVector(0.50f,0.55f,1.0f), fRadius);
	pSphere->SetColor(CRTColor(0.0f, 0.0f, 1.0f));
	scene.AddObject(pSphere);

	pSphere = new CRTSphere(CRTVector(0.50f,0.55f,50.0f), 2.0f);
	pSphere->SetColor(CRTColor(0.7f, 0.7f, 1.0f));
	scene.AddObject(pSphere);

	scene.Render("output.bmp", 640, 480);

	return 0;
}

