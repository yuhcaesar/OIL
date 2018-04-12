package com.icpscloud.base;

import java.io.IOException;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

//import org.apache.log4j.Logger;
import org.apache.struts2.ServletActionContext;

//import com.alibaba.fastjson.JSON;
//import com.opensymphony.xwork2.ActionSupport;

public class BaseAction {

	
//private static final Logger logger = Logger.getLogger(BaseAction.class);
	
	public HttpSession getSession() {
		return getRequest().getSession();
	}

	public HttpServletRequest getRequest() {
		return ServletActionContext.getRequest();
	}

	public HttpServletResponse getResponse() {
		return ServletActionContext.getResponse();
	}
}
