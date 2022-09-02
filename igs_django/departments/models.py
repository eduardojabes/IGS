from django.db import models

# Create your models here.
class Departments(models.Model):
    '''
    Holds information about a department.
    '''
    name = models.CharField(max_length=60, blank=False, null=False)