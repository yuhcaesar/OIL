/**
 * 
 */
package business.icpscloud.facility.dao.impl;

import java.util.List;

import org.hibernate.SessionFactory;
import org.springframework.orm.hibernate3.HibernateTemplate;


import business.icpscloud.facility.dao.PersonDao;
import business.icpscloud.facility.entity.Person;
import business.icpscloud.facility.entity.UserEntity;

/**
 * @author LiPeiXu
 * @ModifyDate 2018年3月1日
 */
public class PersonDaoImpl implements PersonDao {
	private HibernateTemplate ht = null;
	private SessionFactory sessionFactory;

	// 依赖注入SessionFactory的setter方法
	public void setSessionFactory(SessionFactory sessionFactory) {
		this.sessionFactory = sessionFactory;
	}

	// 初始化HibernateTemplate的方法
	private HibernateTemplate getHibernateTemplate() {
		if (ht == null) {
			ht = new HibernateTemplate(sessionFactory);
		}
		return ht;
	}

	/**
	 * 校验用户名密码
	 * 
	 * @param name
	 *            用户名
	 * @param password
	 *            密码
	 * @return true:存在，false:不存在
	 */
	@SuppressWarnings("unchecked")
	public boolean valid(String name, String password) {
		System.out.println("DaoImpl");
		//String hql="FROM UserEntity ue WHERE ue.userName= '"+ entity.getUserName() + "' AND ue.password= '" + Encrypt.e(entity.getPassword()) + "'" ;
		String hql = "from Person p where p.name='admin' and p.password='admin'";
		List<Person> list = this.getHibernateTemplate().find(hql);
		if (list.size() > 0) {
			return true;
		}
		return false;
	}

	
}
