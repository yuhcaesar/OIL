#ifndef __param_H__
#define __param_H__
#include <time.h>
using namespace std;

class CParam
{
private:
        CParam();
        static CParam* m_pInstance;

        int m_OnSampleInterval;
        int m_OffSampleInterval;
        int m_OffLatency;
        int m_DepolInterval;
        int m_PolInterval;
        int m_AsynInterval;
        int m_AssiInterval;
        int m_StabCount;
        int m_StabErr;
        int m_TiggThreshold;
        int m_MeasureOpt;
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
        void setMeasureOpt(int opt);
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
        int getMeasureOpt();
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
