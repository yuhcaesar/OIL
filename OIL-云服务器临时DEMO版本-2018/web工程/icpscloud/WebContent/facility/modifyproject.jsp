<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<link rel="stylesheet" href="${pageContext.request.contextPath}/bootstrap/css/bootstrap.min.css"/>
<link rel="stylesheet" type="text/css" href="../css/style.css">
<link rel="stylesheet" type="text/css" href="../css/base.css">
<link rel="stylesheet" type="text/css" href="../css/detail.css">
<script src="echarts.min.js"></script>
<script type="text/javascript" src="jquery-3.2.1.min.js"></script>
<script type="text/javascript" src="${pageContext.request.contextPath}/bootstrap/js/bootstrap.min.js"></script>
<title>编辑项目</title>
</head>
<body>
	<div class="top">
		<div class="center">
			<span class="left">欢迎来到东北大学物联网云平台，请 <a href="#">登录</a> | <a href="#">注册</a></span>
			<span class="right"><a href="#">帮助我们</a> | <a href="#">关于我们</a></span>
		</div>
	</div>
	<div class="header">
		<div class="center">
			<span>东北大学物联网云平台</span>
			<img src="../images/by.png">
		</div>
	</div>
	
        <div id="content-l">
			<div class="page-header"><h1>修改项目<small></small></h1></div>	
			<form class="form" role="form" action="modifyProjectResult">
				<input type="hidden" name="projectId" value="${pro.project_id}"/>
				<input type="hidden" name="departmentId" value="${pro.department_id}"/>
				<div class="form-group">
					<label class="col-sm-1">项目名称</label>
					<input type="text" class="form-control" value="${pro.project_name}" name="pro.project_name"/>
				</div>
				<div class="form-group">
					<label class="col-sm-1">成员</label>
					<s:checkboxlist name="userIds" list="userList" listKey="user_id" listValue="realname" value="users"></s:checkboxlist>
				</div>
				<div class="form-group">
					<label class="col-sm-1">设备</label>
					<s:checkboxlist name="facilityIds" list="facilityList" listKey="id" listValue="devname" value="facs"></s:checkboxlist><br>
				</div>
				<div class="btn-group btn-group-lg">
					<button type="submit" class="btn btn-default">修改</button>
		  			<button type="reset" class="btn btn-default">重置</button>
		   			<button type="button" class="btn btn-default" onclick="javascript:history.back();">取消</button>
		   			<button type="button" class="btn btn-default" onclick="location.href='deleteProject?projectId=<s:property value="#pro.project_id"/>'">删除</button>
				</div>
			</form>
         </div>                              
    <div class="footer">
        <span>Copyright © 2017 东北大学物联网云平台</span>
        <span>技术支持：物联网实验室</span>
    </div>
</body>
</html>