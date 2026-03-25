<%@ page contentType="text/html; charset=UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Table Example with Form</title>
</head>
<body bgcolor="#fdf5e6">
    <h1>A Table Generating Example</h1>

    <form action="TableExampleWithForm.jsp">
        Row Count: <input type="text" name="rowCount"><br>
        Column Count: <input type="text" name="columnCount"><br>
        <input type="submit" value="Make Table">
    </form>
    <br>

    <% 
        String r = request.getParameter("rowCount");
        String c = request.getParameter("columnCount");

        int rows = 0;
        int cols = 0;

        if (r != null && c != null) {
            rows = Integer.parseInt(r);
            cols = Integer.parseInt(c);
        }

        if (rows > 0 && cols > 0) { 
    %>
        <table border="1">
            <tr>
            <% for (int j = 1; j <= cols; j++) { %>
                <th> Header <%= j %> </th>
            <% } %>
            </tr>

            <% for (int i = 1; i <= rows; i++) { %>
               <tr>
               <% for (int j = 1; j <= cols; j++) { %>
                 <td>row <%= i %>, col <%= j %> </td>
               <% } %>
               </tr>
            <% } %>
        </table>
    <% } %>
</body>
</html>

<%-- http://localhost/myproject/TableExampleWithForm.jsp --%>
