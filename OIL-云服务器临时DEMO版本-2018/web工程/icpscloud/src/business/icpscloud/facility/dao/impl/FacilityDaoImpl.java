/**
 * 
 */
package business.icpscloud.facility.dao.impl;

import java.util.List;

import org.hibernate.Query;
import org.hibernate.classic.Session;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

import business.icpscloud.facility.dao.FacilityDao;
//import business.icpscloud.facility.entity.FacilityDataEntity;
import business.icpscloud.facility.entity.FacilityEntity;

/**
 * @author LiPeiXu
 * @ModifyDate 2017Äê6ÔÂ20ÈÕ
 */
public class FacilityDaoImpl extends HibernateDaoSupport implements FacilityDao {

	@Override
	public FacilityEntity findById() {
		String hql = "FROM FacilityEntity";
		//String hql = "SELECT  FROM iot_businessid_dev dv WHERE dv.devid ='"+id+"'";
		@SuppressWarnings("unchecked")
		List<FacilityEntity> list = this.getHibernateTemplate().find(hql);
		if(!list.isEmpty()){
			return list.get(0);
		}else{
			return null;
		}	
	}
//	@Override
//	public FacilityDataEntity findDevData(String id) {
//		String hql = "FROM FacilityDataEntity fd  WHERE fd.devid ='"+id+"'";
//		System.out.println(id);		
//		@SuppressWarnings("unchecked")
//		List<FacilityDataEntity> list = this.getHibernateTemplate().find(hql);
//		if(!list.isEmpty()){
//			return list.get(1);
//		}else{
//			return null;
//		}	
//	}
//	@Override
//	public List<FacilityDataEntity> findDevDataList(String id) {	      
//		String hql = "FROM FacilityDataEntity fd WHERE fd.devid ='"+id+"' ";		
//		//Query query = this.getSession().createQuery(hql);
//		//System.out.println(query.list());
//		//return query.list();
//		return (List<FacilityDataEntity>) this.getSession().createQuery(hql).list();
//	}

	/* (non-Javadoc)
	 * @see business.icpscloud.facility.dao.FacilityDao#findListByLimit(int, int)
	 */
	@Override
	public List<FacilityEntity> findListByLimit(int index, int size) {
		//String hql = "FROM BusinessNeedEntity cc ORDER BY cc.releaseTime " + orderMethod ;
        String hql = "FROM FacilityEntity ft ORDER BY ft.DataID DESC"  ;	
		Query query = this.getSession().createQuery(hql);
		query.setFirstResult(index);
		query.setMaxResults(size);
		return query.list();
	}
}
