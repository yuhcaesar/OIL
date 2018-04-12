<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<h2>云平台企业用户注册</h2>
<s:form action ="regist2.action">
      <s:textfield name="businessName" key ="企业名称"/>
      <s:password name="password" key = "密码"/>
      <s:textfield name="tel" key = "联系方式"/>
      <s:submit value="提交" key = "提交"/>
 </s:form>
</body>
</html>