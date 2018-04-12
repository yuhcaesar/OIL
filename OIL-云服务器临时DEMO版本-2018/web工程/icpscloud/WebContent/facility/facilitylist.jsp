<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
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

<title>设备列表</title>
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
           <!-- 普通员工视角 -->
<c:if test="${!empty projectList}">
	<div class="page-header"><h1>项目设备列表<small>点击项目名称展开设备列表</small></h1></div>
	<div class="panel-group" id="accordion">
	<s:iterator var="pro" value="projectList">
		<div class="panel panel-default">
			<div class="panel-heading">
				<div class="panel-title collapsed">
					<a class="btn btn-default pull-right" href="projectDetail?projectId=<s:property value="#pro.project_id"/>">项目详细信息</a>
					<h4 data-toggle="collapse" data-parent="#accordion" data-target="#${pro.project_id }">
						<s:property value="#pro.project_name"/>
					</h4>
				</div>
			</div>
			<div id="${pro.project_id }" class="panel-collapse collapse">
				<s:iterator var="fac" value="#pro.facilities">
					<div class="panel-body">
						<a href="getDevDetailAction?devid=<s:property value="#fac.devid"/>">
							<s:property value="#fac.devname"/><small>&nbsp;&nbsp;&nbsp;&nbsp;SN:<s:property value="#fac.devid"/></small>
						</a>
					</div>
				</s:iterator>
			</div>
		</div>
	</s:iterator>
	</div>
  </c:if>
  	
 <!-- 企业管理员视角 -->
 <c:if test="${!empty facilityList}">
 	<div class="page-header"><h1>企业设备列表<small>点击查看设备详情</small></h1></div>
 		<div class="panel panel-default">
				<div class="panel-heading">
					<h4 class="panel-title text-center" data-toggle="collapse" data-target="#allFacility">
						企业全部设备
					</h4>
				</div>
			<div id="allFacility" class="panel-collapse">
				<s:iterator var="fac" value="facilityList">
					<div class="panel-body">
						<a href="getDevDetailAction?devid=<s:property value="#fac.devid"/>">
							<s:property value="#fac.devname"/><small>&nbsp;&nbsp;&nbsp;&nbsp;SN:<s:property value="#fac.devid"/></small>
						</a>
					</div>
				</s:iterator>
			</div>
		</div>
</c:if>

<!-- 部门管理员视角 -->
<c:if test="${!empty notUseFacilityList or !empty departmentProjectList}">
	<div class="page-header">
		<h1>部门设备列表<small>点击项目名称展开设备列表</small>
		<a class="btn btn-default pull-right" href="createProject?departmentId=<s:property value="departmentId"/>">创建新项目</a>
		</h1>
	</div>
</c:if>
 <c:if test="${!empty notUseFacilityList}">
 		<div class="panel panel-default">
				<div class="panel-heading">
					<h4 class="panel-title collapsed text-center" data-toggle="collapse" data-target="#allFacility">
						部门空闲设备
					</h4>
				</div>
			<div id="allFacility" class="panel-collapse collapse">
				<s:iterator var="fac" value="notUseFacilityList">
					<div class="panel-body">
						<a href="getDevDetailAction?devid=<s:property value="#fac.devid"/>">
							<s:property value="#fac.devname"/><small>&nbsp;&nbsp;&nbsp;&nbsp;SN:<s:property value="#fac.devid"/></small>
						</a>
					</div>
				</s:iterator>
			</div>
		</div>
</c:if>
<c:if test="${!empty departmentProjectList}">
	<div class="panel-group" id="accordion">
	<s:iterator var="pro" value="departmentProjectList">
		<div class="panel panel-default">
			<div class="panel-heading">
				<div class="panel-title collapsed">
					<div class="btn-group pull-right">
						<a class="btn btn-default" href="projectDetail?projectId=<s:property value="#pro.project_id"/>">项目详细信息</a>
						<a class="btn btn-default" href="modifyProject?projectId=<s:property value="#pro.project_id"/>">编辑项目</a>
					</div>
					<h4  data-toggle="collapse" data-parent="#accordion" data-target="#${pro.project_id }">
						<s:property value="#pro.project_name"/>
					</h4>
				</div>
			</div>
			<div id="${pro.project_id }" class="panel-collapse collapse">
				<s:iterator var="fac" value="#pro.facilities">
					<div class="panel-body">
						<a href="getDevDetailAction?devid=<s:property value="#fac.devid"/>">
							<s:property value="#fac.devname"/><small>&nbsp;&nbsp;&nbsp;&nbsp;SN:<s:property value="#fac.devid"/></small>
						</a>
					</div>
				</s:iterator>
			</div>
		</div>
	</s:iterator>
	</div>
  </c:if>
         </div>                              
    <div class="footer">
        <span>Copyright © 2017 东北大学物联网云平台</span>
        <span>技术支持：物联网实验室</span>
    </div>
    </div>

</body>
</html>