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
<h1>部门管理员修改</h1>
<s:form action ="alert_dept.action">
	  <s:textfield name="departmentId" key ="需要修改的部门编号"/>
      <s:textfield name="managerId" key = "部门管理员编号"/>
      <s:submit value="确认修改" key = "确认修改"/>
 </s:form>
</body>
</html>