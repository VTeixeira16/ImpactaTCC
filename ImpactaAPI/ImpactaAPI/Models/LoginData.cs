using ImpactaAPI.Models;
using System.Collections.ObjectModel;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ImpactaAPI.Models;

[Table("LoginData")]
public class LoginData
{

    [Key]
    public int id { get; set; }

    [StringLength(64)]
    public string? machineName { get; set; }

    public DateTime dateTimeLogin { get; set; }
    //dateTimeLogin
}

