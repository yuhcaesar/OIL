/**
 * 
 */
package business.icpscloud.facility.dao;

import java.util.List;

import business.icpscloud.facility.entity.Person;

/**
 * @author LiPeiXu
 * @ModifyDate 2018年3月1日
 */
public interface PersonDao {
	/**
	 * 校验用户名密码
	 * 
	 * @param name
	 *            用户名
	 * @param password
	 *            密码
	 * @return true:存在，false:不存在
	 */
	public boolean valid(String name, String password);
}
