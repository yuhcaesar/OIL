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

<title>项目详细信息</title>
</head>
<body >
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
			<c:if test="${!empty pro}">
			  	<div class="page-header">
			  		<h1>项目信息<small><s:property value="#pro.project_name"/></small></h1>
			  	</div>
			  	<div class="panel panel-default">
					<div class="panel-heading">
						<h4 class="panel-title text-center" data-toggle="collapse" data-target="#usertable">
							项目成员
						</h4>
					</div>
					<div id="usertable" class="panel-collapse">
						<table class="table table-hover table-striped">
						<tr>
							<th>成员姓名</th>
							<th>成员ID</th>
						</tr>
						<s:iterator var="user" value="#pro.users">
							<tr>
								<td><s:property value="#user.realname"/></td>
								<td><s:property value="#user.user_id"/></td>
							</tr>
						</s:iterator>
						</table>
					</div>
				</div>
				<div class="panel panel-default">
					<div class="panel-heading">
						<h4 class="panel-title text-center" data-toggle="collapse" data-target="#facilitytable"">
							项目设备
						</h4>
					</div>
					<div id="facilitytable" class="panel-collapse">
						<table class="table table-hover table-striped">
						<tr>
							<th>设备名称</th>
							<th>设备ID</th>
							<th>设备SN</th>
						</tr>
						<s:iterator var="fac" value="#pro.facilities">
							<tr>
								<td><s:property value="#fac.devname"/></td>
								<td><s:property value="#fac.id"/></td>
								<td><s:property value="#fac.devid"/></td>
							</tr>
						</s:iterator>
						</table>
					</div>
				</div>
			  </c:if>
           
         </div>                              
    <div class="footer">
        <span>Copyright © 2017 东北大学物联网云平台</span>
        <span>技术支持：物联网实验室</span>
    </div>
 
</body>
</html>