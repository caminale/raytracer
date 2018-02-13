#ifndef __LIGHT_H
#define __LIGHT_H

class CRTLight
{
	public :

		virtual ~CRTLight ()
		{
		}

        void SetColor (const CRTColor &cColor) { m_cColor = cColor ; }
		const CRTColor &GetColor () { return m_cColor ; }

		virtual CRTVector getDirectionTolightAtPoint (const CRTPoint &pPoint) =  0;


	protected :
		CRTColor m_cColor ;
} ;

#endif

