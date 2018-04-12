/**
 * 
 */
package business.icpscloud.facility.action;

import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.ServletActionContext;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import business.icpscloud.facility.entity.UserEntity;
import business.icpscloud.facility.service.MyService;

/**
 * @author LiPeiXu
 * @ModifyDate 2018年3月1日
 */
public class LoginAction extends ActionSupport {
	// 下面是用于封装用户请求参数的两个属性
		private String name;
		private String password;
		// 用于封装处理结果的属性
		private String tip;
		// 系统所用的业务逻辑组件
		private MyService ms;

		// 设置注入业务逻辑组件所必需的setter方法
		public void setMs(MyService ms) {
			this.ms = ms;
		}

		/**
		 * 用户登录
		 * 
		 * @return
		 * @throws Exception
		 */
		public String login() throws Exception {
			// 调用业务逻辑组件的valid方法来
			// 验证用户输入的用户名和密码是否正确
			System.out.println(getName());
			System.out.println(getPassword());
			if (ms.valid(getName(), getPassword())) {
				System.out.println("成功");
				return SUCCESS;
			} else {
				System.out.println("失败");
				return "error";
			}
		}

		public String getName() {
			return name;
		}

		public void setName(String name) {
			this.name = name;
		}

		public String getPassword() {
			return password;
		}

		public void setPassword(String password) {
			this.password = password;
		}

		public String getTip() {
			return tip;
		}

		public void setTip(String tip) {
			this.tip = tip;
		}

		public MyService getMs() {
			return ms;
		}
}
