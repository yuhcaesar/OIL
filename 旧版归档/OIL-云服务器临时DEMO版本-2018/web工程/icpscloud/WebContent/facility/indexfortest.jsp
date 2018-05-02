<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>测试引导页</title>
</head>
<body>
	<h1>查看设备列表</h1>
	<form action="facilitylist_queryByUser" method="post">
	通过User-ID查询项目和设备（1008、1011）：
	<input type="text" name="userId"/>
	<input type="submit" value="查询"/><br>
	</form>
	<form action="facilitylist_queryByDepartment" method="post">
	通过department-ID查询项目和设备（100）：
	<input type="text" name="departmentId"/>
	<input type="submit" value="查询"/><br>
	</form>
	<form action="facilitylist_queryByBusiness" method="post">
	通过bussiness-ID查询项目和设备（1000）：
	<input type="text" name="businessId"/>
	<input type="submit" value="查询"/><br>
	</form>
	<h1>编辑项目</h1>
	<form action="createProject" method="post">
	通过department-ID添加项目（100）：
	<input type="text" name="departmentId"/>
	<input type="submit" value="创建项目"/><br>
	</form>
	<form action="modifyProject" method="post">
	通过project-ID编辑项目（100）：
	<input type="text" name="projectId"/>
	<input type="submit" value="编辑项目"/><br>
	</form>
	<form action="projectDetail" method="post">
	通过project-ID查看项目信息（17、18）：
	<input type="text" name="projectId"/>
	<input type="submit" value="查询"/><br>
	</form>
</body>
</html>