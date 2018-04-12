/**
 * 
 */
package business.icpscloud.facility.service.impl;

import java.util.List;

import business.icpscloud.facility.dao.FacilityDao;
//import business.icpscloud.facility.entity.FacilityDataEntity;
import business.icpscloud.facility.entity.FacilityEntity;
import business.icpscloud.facility.service.FacilityService;

/**
 * @author LiPeiXu
 * @ModifyDate 2017Äê6ÔÂ20ÈÕ
 */
public class FacilityServiceImpl implements FacilityService {
    FacilityDao facilityDao;
	@Override
	public FacilityEntity findById() {		
		return facilityDao.findById();
	}
	
//	@Override
//	public FacilityDataEntity findDevData(String id) {
//		
//		return facilityDao.findDevData(id);
//	}
//	@Override
//	public List<FacilityDataEntity> findDevDataList(String id) {
//		return facilityDao.findDevDataList(id);
//		
//	}
//	
	public FacilityDao getFacilityDao() {
		return facilityDao;
	}
	public void setFacilityDao(FacilityDao facilityDao) {
		this.facilityDao = facilityDao;
	}

	/* (non-Javadoc)
	 * @see business.icpscloud.facility.service.FacilityService#findListByLimit(int, int)
	 */
	@Override
	public List<FacilityEntity> findListByLimit(int index, int size) {
		// TODO Auto-generated method stub
		return facilityDao.findListByLimit(index,size);
	}

	

}
