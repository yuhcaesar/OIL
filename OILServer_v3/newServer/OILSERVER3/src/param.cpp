#include "param.h"
using namespace std;

CParam* CParam::m_pInstance = 0;

CParam::CParam()
{}

CParam* CParam::GetInstance()
{
        if(m_pInstance == 0)
                m_pInstance = new CParam();
        return m_pInstance;
}
        
void CParam::setOnSampleInterval(int interval)
{
        this->m_OnSampleInterval = interval;
}

void CParam::setOffSampleInterval(int interval)
{
        this->m_OffSampleInterval = interval;
}

void CParam::setOffLatency(int latency)
{
        this->m_OffLatency = latency;
}

void CParam::setDepolInterval(int interval)
{
        this->m_DepolInterval = interval;
}

void CParam::setPolInterval(int interval)
{
        this->m_PolInterval = interval;
}

void CParam::setAsynInterval(int interval)
{
        this->m_AsynInterval = interval;
}

void CParam::setAssiInterval(int interval)
{
        this->m_AssiInterval = interval;
}

void CParam::setStabCount(int count)
{
        this->m_StabCount =  count;
}

void CParam::setStabErr(int err)
{
        this->m_StabErr = err;
}

void CParam::setTiggThreshold(int threshold)
{
        this->m_TiggThreshold = threshold;
}

void CParam::setOnMeasureOpt(int opt)
{
        this->m_OnMeasureOpt = opt;
}

void CParam::setOffMeasureOpt(int opt)
{
        this->m_OffMeasureOpt = opt;
}

void CParam::setRangeOpt(int opt)
{
        this->m_RangeOpt = opt;
}

int CParam::getOnSampleInterval()
{
        return this->m_OnSampleInterval;
}

int CParam::getOffSampleInterval()
{
        return this->m_OffSampleInterval;
}

int CParam::getOffLatency()
{
        return this->m_OffLatency;
}

int CParam::getDepolInterval()
{
        return this->m_DepolInterval;
}

int CParam::getPolInterval()
{
        return this->m_PolInterval;
}

int CParam::getAsynInterval()
{
        return this->m_AsynInterval;
}

int CParam::getAssiInterval()
{
        return this->m_AssiInterval;
}

int CParam::getStabCount()
{
        return this->m_StabCount;
}

int CParam::getStabErr()
{
        return this->m_StabErr;
}

int CParam::getTiggThreshold()
{
        return this->m_TiggThreshold;
}

int CParam::getOnMeasureOpt()
{
        return this->m_OnMeasureOpt;
}

int CParam::getOffMeasureOpt()
{
        return this->m_OffMeasureOpt;
}

int CParam::getRangeOpt()
{
        return this->m_RangeOpt;
}

void CParam::setDcPotentialK(float K)
{
        this->m_dcPotentialK = K;
}

void CParam::setDcPotentialB(float B)
{
        this->m_dcPotentialB = B;
}

void CParam::setAcPotentialK(float K)
{
        this->m_acPotentialK = K;
}

void CParam::setAcPotentialB(float B)
{
        this->m_acPotentialB = B;
}

void CParam::setAcHiCurrentK(float K)
{
        this->m_acHiCurrentK = K;
}

void CParam::setAcHiCurrentB(float B)
{
        this->m_acHiCurrentB = B;
}

void CParam::setDcHiCurrentK(float K)
{
        this->m_dcHiCurrentK = K;
}

void CParam::setDcHiCurrentB(float B)
{
        this->m_dcHiCurrentB = B;
}

void CParam::setAcLoCurrentK(float K)
{
        this->m_acLoCurrentK = K;
}

void CParam::setAcLoCurrentB(float B)
{
        this->m_acLoCurrentB = B;
}

void CParam::setDcLoCurrentK(float K)
{
        this->m_dcPotentialK = K;
}

void CParam::setDcLoCurrentB(float B)
{
        this->m_dcLoCurrentB = B;
}

float CParam::getDcPotentialK()
{
        return m_dcPotentialK;
}

float CParam::getDcPotentialB()
{
        return m_dcPotentialB;
}

float CParam::getAcPotentialK()
{
        return m_acPotentialK;
}

float CParam::getAcPotentialB()
{
        return m_acPotentialB;
}

float CParam::getAcHiCurrentK()
{
        return m_acHiCurrentK;
}

float CParam::getAcHiCurrentB()
{
        return m_acHiCurrentB;
}
float CParam::getDcHiCurrentK()
{
        return m_dcHiCurrentK;
}

float CParam::getDcHiCurrentB()
{
        return m_dcHiCurrentB;
}
float CParam::getAcLoCurrentK()
{
        return m_acLoCurrentK;
}
float CParam::getAcLoCurrentB()
{
        return m_acLoCurrentB;
}
float CParam::getDcLoCurrentK()
{
        return m_dcLoCurrentK;
}

float CParam::getDcLoCurrentB()
{
        return m_dcLoCurrentB;
}
