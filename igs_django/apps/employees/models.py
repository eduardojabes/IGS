from django.db import models
from apps.departments.models import Departments

class Employees(models.Model):
    department_id = models.ForeignKey(Departments, on_delete=models.CASCADE)
    name = models.CharField(max_length=200)
    email = models.IntegerField(default=0)