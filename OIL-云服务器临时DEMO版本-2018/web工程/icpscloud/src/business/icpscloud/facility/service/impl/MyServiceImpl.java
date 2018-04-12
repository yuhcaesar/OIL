/**
 * 
 */
package business.icpscloud.facility.service.impl;

import business.icpscloud.facility.dao.PersonDao;
import business.icpscloud.facility.service.MyService;

/**
 * @author LiPeiXu
 * @ModifyDate 2018年3月1日
 */
public class MyServiceImpl implements MyService {
	private PersonDao personDao;

	/**
	 * 校验用户名密码
	 * 
	 * @param name
	 *            用户名
	 * @param password
	 *            密码
	 * @return true:存在，false:不存在
	 */
	public boolean valid(String name, String password) {
		System.out.println("ServiceImpl");
		return personDao.valid(name, password);
	}

	public PersonDao getPersonDao() {
		return personDao;
	}

	public void setPersonDao(PersonDao personDao) {
		this.personDao = personDao;
	}
}
