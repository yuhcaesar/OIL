#ifndef __param_H__
#define __param_H__
#include <time.h>
using namespace std;

class CParam
{
private:
        CParam();
        static CParam* m_pInstance;

        int m_OnSampleInterval = 20;
        int m_OffSampleInterval = 12;
        int m_OffLatency = 500;
        int m_DepolInterval = 1000;
        int m_PolInterval = 30;
        int m_AsynInterval = 30;
        int m_AssiInterval = 2;
        int m_StabCount = 3;
        int m_StabErr = 10;
        int m_TiggThreshold = -850;
        int m_OnMeasureOpt = 1;
        int m_OffMeasureOpt = 1;
        int m_RangeOpt;

        float m_dcPotentialK;
        float m_dcPotentialB;
        float m_acPotentialK;
        float m_acPotentialB;
        float m_acHiCurrentK;
        float m_acHiCurrentB;
        float m_dcHiCurrentK;
        float m_dcHiCurrentB;
        float m_acLoCurrentK;
        float m_acLoCurrentB;
        float m_dcLoCurrentK;
        float m_dcLoCurrentB;
        
public:
        static CParam* GetInstance();
                        
        void setOnSampleInterval(int interval);
        void setOffSampleInterval(int interval);
        void setOffLatency(int latency);
        void setDepolInterval(int interval);
        void setPolInterval(int interval);
        void setAsynInterval(int interval);
        void setAssiInterval(int interval);
        void setStabCount(int count);
        void setStabErr(int err);
        void setTiggThreshold(int threshold);
        void setOnMeasureOpt(int opt);
        void setOffMeasureOpt(int opt);
        void setRangeOpt(int opt);

        int getOnSampleInterval();
        int getOffSampleInterval();
        int getOffLatency();
        int getDepolInterval();
        int getPolInterval();
        int getAsynInterval();
        int getAssiInterval();
        int getStabCount();
        int getStabErr();
        int getTiggThreshold();
        int getOnMeasureOpt();
        int getOffMeasureOpt();
        int getRangeOpt();

        void setDcPotentialK(float K);
        void setDcPotentialB(float B);
        void setAcPotentialK(float K);
        void setAcPotentialB(float B);
        void setAcHiCurrentK(float K);
        void setAcHiCurrentB(float B);
        void setDcHiCurrentK(float K);
        void setDcHiCurrentB(float B);
        void setAcLoCurrentK(float K);
        void setAcLoCurrentB(float B);
        void setDcLoCurrentK(float K);
        void setDcLoCurrentB(float B);

        float getDcPotentialK();
        float getDcPotentialB();
        float getAcPotentialK();
        float getAcPotentialB();
        float getAcHiCurrentK();
        float getAcHiCurrentB();
        float getDcHiCurrentK();
        float getDcHiCurrentB();
        float getAcLoCurrentK();
        float getAcLoCurrentB();
        float getDcLoCurrentK();
        float getDcLoCurrentB();

        
};
#endif
