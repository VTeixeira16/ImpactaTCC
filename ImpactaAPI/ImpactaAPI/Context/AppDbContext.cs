using ImpactaAPI.Models;
using Microsoft.EntityFrameworkCore;

namespace ImpactaAPI.Context;

public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
    {
    }

    public DbSet<Categoria>? Categorias { get; set; }
    public DbSet<Produto>? Produtos { get; set; }

    public DbSet<LoginData>? LoginDataDb { get; set; }

    public DbSet<HitsNumber>? HitsNumberDb { get; set; }

    public DbSet<GamesNumber>? GamesNumberDb{ get; set; }
}
